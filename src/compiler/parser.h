/* A packrat parser generated by PackCC 3.0.0 */

#ifndef PCC_INCLUDED_PARSER_H
#define PCC_INCLUDED_PARSER_H

#include "../utils/ast.h"
#include "parser_utils.h"

// Use YY_CTX_LOCAL to avoid thread-local context issues
#define YY_CTX_LOCAL 1

// Define maximum stack size to prevent infinite recursion
#define YY_MAX_STACK_SIZE 1000

// Define maximum repetition count to prevent infinite loops
#define PCC_INFINITE_LOOP_DETECT 1000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct vibe_context_tag vibe_context_t;

vibe_context_t *vibe_create(void*auxil);
int vibe_parse(vibe_context_t *ctx, ast_node_t**ret);
void vibe_destroy(vibe_context_t *ctx);

#ifdef __cplusplus
}
#endif

#endif /* !PCC_INCLUDED_PARSER_H */
