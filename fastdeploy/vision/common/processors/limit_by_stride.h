// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "fastdeploy/vision/common/processors/base.h"

namespace fastdeploy {
namespace vision {

class LimitByStride : public Processor {
 public:
  explicit LimitByStride(int stride = 32, int interp = 1) {
    stride_ = stride;
    interp_ = interp;
  }

  // Resize Mat* mat to make the size divisible by stride_.

  bool ImplByOpenCV(Mat* mat);
  std::string Name() { return "LimitByStride"; }

  static bool Run(Mat* mat, int stride = 32, int interp = 1,
                  ProcLib lib = ProcLib::OPENCV);

 private:
  int interp_;
  int stride_;
};
}  // namespace vision
}  // namespace fastdeploy
