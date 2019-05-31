#include "AnonymousFunctionExpression.h"
#include "../../lib/functions/UserFunction.h"

Value AnonymousFunctionExpression::eval() {
    return Value(new UserFunction("anonymous", args, body));
}
