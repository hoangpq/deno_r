export const SYMBOLS = {
  deno_init_embedded: {
    parameters: [],
    result: "void",
  },
  deno_release_embedded: {
    parameters: [],
    result: "void",
  },
  deno_invoke_add1: {
    parameters: ["pointer"],
    result: "i32",
  },
  deno_new_i32_vector: {
    parameters: ["i32", "pointer"],
    result: "pointer",
  },
} as const;
