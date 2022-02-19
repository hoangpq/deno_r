use r_sys::SEXP;

macro_rules! export {
    ($rename: ident, fn $name:ident($( $arg:ident : $type:ty ),*) -> $ret:ty) => {
        #[no_mangle]
        #[doc = "# Safety"]
        #[doc = ""]
        #[doc = "This function is unsafe for obvious reasons."]
        pub unsafe extern "C" fn $rename($( $arg : $type),*) -> $ret {
            r_sys::$name($( $arg ),*)
        }
    };
    ($rename: ident, fn $name:ident($( $arg:ident : $type:ty ),*)) => {
        export!($rename, fn $name($( $arg : $type),*) -> ());
    }
}

export!(deno_init_embedded, fn init_embedded_r());
export!(deno_release_embedded, fn release_embedded_r());
export!(deno_invoke_add1, fn invoke(arg: SEXP) -> i32);
export!(deno_new_i32_vector, fn new_integer_vector(len: i32, ptr: *const i32) -> SEXP);
