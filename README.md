
#### Why？
尝试使用protobuf+wasm将proto结构解析层使用c++实现，并暴露给前端js，使得解析层统一实现，并暴露统一接口。
此项目为实验proto+wasm暴露对应的c层对应类以及接口是否可行

#### Env
项目依赖:
- unix*
- Docker


#### How ?

`build-docker-env` 提供用来编译基础依赖的镜像，镜像包含protobuf以及emsdk
`yarn build` 将根据cmake编译src内的c++代码生成helloworld.js




#### Q&A

##### Q: 什么是test_post_script.js


在docker-build.sh脚本内设置了编译参数`--post-js ../test_post_script.js`,其实就是会将--post-js脚本内的代码放到<output>.js最后，  
而`__ATPOSTRUN__`是一个Emscripten Runtime Environment内部的一个生命周期Hook队列，  
`functions called after the runtime has exited` 即当runtime退出时会调用`__ATPOSTRUN__`队列内的函数






