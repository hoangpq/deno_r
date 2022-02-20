import { c, r_call, r_load, runR, Sexp } from "../mod.ts";

runR(() => {
  r_load("examples/func.R");
  r_call("add1", c(1, 2, 3, 4, 5));
  r_call("add2", c("hello", "world"));
});
