import { int32list, invoke_add1, runR } from "../mod.ts";

runR(() => {
  const arg = int32list(1, 2, 3, 4, 5);
  invoke_add1(arg);
});
