#ifndef BINDING_H
#define BINDING_H

#include <stdio.h>
#include <string.h>

#include <Rinternals.h>
#include <Rembedded.h>

#ifndef R_API
#define R_API extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

// VM
R_API void init_vm_r();
R_API void release_vm_r();

R_API SEXP c(u_int32_t, int *);
R_API void r_load(const char *);
R_API void r_call(const char *, SEXP);

#ifdef __cplusplus
}
#endif

#endif /* BINDING_H */
