build:
	cargo build

fmt:
	cargo fmt
	deno fmt --ignore=target/

example:
	deno run --unstable -A examples/simple.ts

all: fmt build example
