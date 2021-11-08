

#### Why？
尝试使用protobuf+wasm将proto结构解析层使用c++实现，并暴露给前端js，使得解析层统一实现，并暴露统一接口。
此项目为实验proto+wasm暴露对应的c层对应类以及接口是否可行

#### How ?

`bash docker-build.sh -h` 将提供对应的帮助方法  
`bash docker-build.sh -build` 提供用来编译基础依赖的镜像，镜像包含protobuf以及emsdk
`bash docker-build.sh -make` 将根据cmake编译src内的c++代码生成helloworld.js




#### Q&A

##### Q: 什么是test_post_script.js
__ATPOSTRUN__


