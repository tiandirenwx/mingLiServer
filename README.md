# mingLiServer

## 命理服务

### 基于开源 `trpc-cpp` 框架编写

#### 说明：
1. **开源项目基础**：
   - 本程序基于以下开源项目，仅限于兴趣研究，无任何商业化目的。如有侵权，请通知我删除代码。
   - 项目链接：[trpc-cpp](https://github.com/trpc-group/trpc-cpp.git)

2. **程序使用**：
   - **CMake 编译**：
      1. 创建构建目录：
         ```bash
         mkdir -p build
         ```
      2. 运行 CMake 构建：
         ```bash
         cmake ..
         make
         ```
   - **Bazel 编译**：
      1. 进入 `paipan` 目录：
         ```bash
         cd paipan
         ```
      2. 运行构建脚本：
         ```bash
         ./build.sh
         ```
      - **注意事项**：Bazel 编译是由 `trpc-cpp` 框架生成，不建议与 CMake 混合编译。请选择其中一种方式进行编译。

#### 其他信息：
- 请确保在编译和运行程序时遵循相关开源协议和法律法规。