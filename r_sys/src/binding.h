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

R_API int invoke(SEXP);
R_API void init_embedded_r();
R_API void release_embedded_r();
R_API SEXP new_integer_vector(int, int *);

#ifdef __cplusplus
}
#endif

#endif /* BINDING_H */
