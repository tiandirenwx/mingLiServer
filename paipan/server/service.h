#pragma once

#include "proto/paipan.trpc.pb.h"

namespace trpc {
namespace bazi {
namespace paipan {

class BaziPaipanServiceImpl : public ::trpc::bazi::paipan::BaziPaipan {
 public:
  ::trpc::Status GetBaziPaipan(::trpc::ServerContextPtr context, const ::trpc::bazi::paipan::BaziPaiPanRequest* request, ::trpc::bazi::paipan::BaziPaiPanReply* reply) override;
};

}  // namespace paipan
}  // namespace bazi
}  // namespace trpc
