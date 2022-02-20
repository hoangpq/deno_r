import { c, r_call, r_load, runR } from "../mod.ts";

runR(() => {
  r_load("examples/func.R");
  const arg = c(1, 2, 3, 4, 5);
  r_call("add1", arg);
});
