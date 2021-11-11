// import Module from "./eproto.js"
const Module = require("./eproto.js");


Module.init(()=>{
        //创建一个xClass类对象
        var xClass = new Module.xClass(100,"Hello World !!!");
        //打印该对象的私有成员变量x的值
        console.log(xClass['x']);
        //通过set函数赋值
        xClass['x']=98;
        //再次打印该对象的私有成员变量x的值
        console.log(xClass['x']);
        //调用该对象的成员函数
        xClass.incrementX();
        //再次打印该对象的私有成员变量x的值
        console.log(xClass['x']);
        //调用定义在该对象下的静态方法
        console.log(Module['xClass']['getStringValue'](xClass));
        console.log(Module['xClass']['PrintNum']());
        //析构该对象实例，释放wasm共享线性内存空间
        xClass.delete();
})

