const encoder = new TextEncoder();

export function encode(value: string) {
  return encoder.encode(value + "\0");
}
