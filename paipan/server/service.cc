#include "server/service.h"

#include "trpc/log/trpc_log.h"

namespace trpc {
namespace bazi {
namespace paipan {

::trpc::Status BaziPaipanServiceImpl::GetBaziPaipan(::trpc::ServerContextPtr context, const ::trpc::bazi::paipan::BaziPaiPanRequest* request, ::trpc::bazi::paipan::BaziPaiPanReply* reply) {
  // Implement business logic here
  TRPC_FMT_INFO("got req");
  return ::trpc::kSuccStatus;
}

}  // namespace paipan
}  // namespace bazi
}  // namespace trpc
