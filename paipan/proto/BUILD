package(default_visibility = ["//visibility:public"])

load("@trpc_cpp//trpc:trpc.bzl", "trpc_proto_library")

trpc_proto_library(
    name = "proto_paipan_proto",
    srcs = ["proto/paipan.proto"],
    rootpath = "@trpc_cpp",
    use_trpc_plugin = True,
)
