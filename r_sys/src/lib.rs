use std::ffi::c_void;

#[allow(non_camel_case_types)]
pub type SEXP = *mut c_void;

extern "C" {
    pub fn init_embedded_r();
    pub fn release_embedded_r();
    pub fn invoke(arg: SEXP) -> i32;
    pub fn new_integer_vector(len: i32, ptr: *const i32) -> SEXP;
}
