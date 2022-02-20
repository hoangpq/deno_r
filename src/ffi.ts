export const SYMBOLS = {
  r_init_vm: {
    parameters: [],
    result: "void",
  },
  r_release_vm: {
    parameters: [],
    result: "void",
  },
  r_load: {
    parameters: ["pointer"],
    result: "void",
  },
  r_call: {
    parameters: ["pointer", "pointer"],
    result: "void",
  },
  r_c: {
    parameters: ["i32", "pointer"],
    result: "pointer",
  },
} as const;
