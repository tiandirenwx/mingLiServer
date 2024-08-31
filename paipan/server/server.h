#pragma once

#include "trpc/common/trpc_app.h"

namespace trpc {
namespace bazi {
namespace paipan {

class PaipanServer : public ::trpc::TrpcApp {
 public:
  int Initialize() override;

  void Destroy() override;
};

}  // namespace paipan
}  // namespace bazi
}  // namespace trpc
