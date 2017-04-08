#pragma once

#include <vector>
#include <memory>
#include <utility>
#include "../../base/macros.h"
#include "action.h"

using std::unique_ptr;
using std::make_unique;

NS_HC_BEGIN

using ActionVector = vector<unique_ptr<Action>>;
class Sequence {
public:
  Sequence() : actions_(new ActionVector()){};

private:
  ActionVector *actions_;
};
NS_HC_END
