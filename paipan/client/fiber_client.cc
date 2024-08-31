#include <iostream>
#include <string>

#include "gflags/gflags.h"

#include "trpc/client/make_client_context.h"
#include "trpc/client/trpc_client.h"
#include "trpc/common/runtime_manager.h"
#include "trpc/log/trpc_log.h"

#include "proto/paipan.trpc.pb.h"

DEFINE_string(client_config, "trpc_cpp.yaml", "framework client config file, --client_config=trpc_cpp.yaml");
DEFINE_string(service_name, "trpc.bazi.paipan.BaziPaipan", "callee service name");


int BaziPaipanGetBaziPaipan(const std::shared_ptr<::trpc::bazi::paipan::BaziPaipanServiceProxy>& proxy) {
  ::trpc::ClientContextPtr client_ctx = ::trpc::MakeClientContext(proxy);
  ::trpc::bazi::paipan::BaziPaiPanRequest req;
  // fill some filed of req
  ::trpc::bazi::paipan::BaziPaiPanReply rsp;
  ::trpc::Status status = proxy->GetBaziPaipan(client_ctx, req, &rsp);
  if (!status.OK()) {
    std::cerr << "get rpc error: " << status.ErrorMessage() << std::endl;
    return -1;
  }
  std::cout << "get rsp success" << std::endl;
  return 0;
}

int Run() {
  auto proxy = ::trpc::GetTrpcClient()->GetProxy<::trpc::bazi::paipan::BaziPaipanServiceProxy>(FLAGS_service_name);
  return BaziPaipanGetBaziPaipan(proxy);
}

void ParseClientConfig(int argc, char* argv[]) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  google::CommandLineFlagInfo info;
  if (GetCommandLineFlagInfo("client_config", &info) && info.is_default) {
    TRPC_FMT_ERROR("start client with config, for example:{} --client_config=/client/config/filepath", argv[0]);
    exit(-1);
  }
  
  std::cout << "FLAGS_service_name: " << FLAGS_service_name << std::endl;
  std::cout << "FLAGS_client_config: " << FLAGS_client_config << std::endl;

  int ret = ::trpc::TrpcConfig::GetInstance()->Init(FLAGS_client_config);
  if (ret != 0) {
    std::cerr << "load client_config failed." << std::endl;
    exit(-1);
  }
}

int main(int argc, char* argv[]) {
  ParseClientConfig(argc, argv);
  // If the business code is running in trpc pure client mode,
  // the business code needs to be running in the `RunInTrpcRuntime` function
  // This function can be seen as a program entry point and should be called only once.
  return ::trpc::RunInTrpcRuntime([]() {
    return Run();
  });
}
