use std::ffi::c_void;
use std::os::raw::c_char;

#[allow(non_camel_case_types)]
pub type SEXP = *mut c_void;

extern "C" {
    pub fn init_vm_r();
    pub fn release_vm_r();
    pub fn r_load(module: *const c_char);
    pub fn r_call(method: *const c_char, arg: SEXP);
    pub fn c(len: u32, ptr: *const i32) -> SEXP;
}
