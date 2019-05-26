#ifndef MALIX_MATHPACKAGE_H
#define MALIX_MATHPACKAGE_H


#include "Package.h"
#include "../functions/NativeFunction.h"
#include "../functions/maths/MathFunctions.h"

class MathPackage : public Package {
public :
    std::string getName() override;
    std::vector<Function *> getFunctions() override;
    std::map<std::string, Value> getConstants() override;
};


#endif //MALIX_MATHPACKAGE_H
