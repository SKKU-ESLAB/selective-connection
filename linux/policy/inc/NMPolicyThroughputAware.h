/* Copyright 2017-2018 All Rights Reserved.
 *  Gyeonghwan Hong (redcarrottt@gmail.com)
 *
 * [Contact]
 *  Gyeonghwan Hong (redcarrottt@gmail.com)
 *
 * Licensed under the Apache License, Version 2.0(the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __NM_POLICY_THROUGHPUT_AWARE_H__
#define __NM_POLICY_THROUGHPUT_AWARE_H__

#include "../../core/inc/NMPolicy.h"

namespace sc {
class NMPolicyThroughputAware : public NMPolicy {
public:
  NMPolicyThroughputAware(void) {
    this->mWFDMode = false;
    this->mIncreaseCount = 0;
    this->mDecreaseCount = 0;
  }
  virtual std::string get_stats_string(void);
  virtual std::string get_name(void) {
    std::string str("Fully manual");
    return str;
  }
  virtual void on_custom_event(std::string &event_description);
  virtual SwitchBehavior decide(const Stats &stats, bool is_increasable,
                                bool is_decreasable);

private:
  bool mWFDMode;

  int mIncreaseCount;
  int mDecreaseCount;
}; /* class NMPolicyThroughputAware */
} /* namespace sc */

#endif /* defined(__NM_POLICY_THROUGHPUT_AWARE_H__) */