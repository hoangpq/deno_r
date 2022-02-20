import __ from "https://deno.land/x/dirname@1.1.2/mod.ts";
import * as path from "https://deno.land/std@0.125.0/path/mod.ts";

const { __dirname } = __(import.meta);

import { SYMBOLS } from "./ffi.ts";
import { encode } from "./util.ts";

let R!: Deno.DynamicLibrary<typeof SYMBOLS>["symbols"];

try {
  R = Deno.dlopen(
    path.join(__dirname, "..", "/target/debug/libr_binding.dylib"),
    SYMBOLS,
  ).symbols;
} catch (e) {
  console.log(e.message);
}

type SEXP = any;

export function r_load(path: string) {
  R.r_load(encode(path));
}

export function r_call(func: string, arg: SEXP) {
  R.r_call(encode(func), arg);
}

export function c(...elements: number[]): SEXP {
  const buf = new Uint32Array(elements);
  return R.r_c(buf.length, buf);
}

export function runR(handler: () => any) {
  R.r_init_vm();
  handler();
  R.r_release_vm();
}
