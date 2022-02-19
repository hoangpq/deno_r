import __ from "https://deno.land/x/dirname@1.1.2/mod.ts";
import * as path from "https://deno.land/std@0.125.0/path/mod.ts";

const { __dirname } = __(import.meta);

import { SYMBOLS } from "./ffi.ts";

let R!: Deno.DynamicLibrary<typeof SYMBOLS>["symbols"];

try {
  R =
    Deno.dlopen(
      path.join(__dirname, "..", "/target/debug/libr_binding.dylib"),
      SYMBOLS,
    ).symbols;
} catch (e) {
  console.log(e.message);
}

type SEXP = any;

export const invoke_add1 = R.deno_invoke_add1;

export function int32list(...elements: number[]): SEXP {
  const buf = new Uint32Array(elements);
  return R.deno_new_i32_vector(buf.length, buf);
}

export function runR(handler: () => any) {
  R.deno_init_embedded();
  handler();
  R.deno_release_embedded();
}
