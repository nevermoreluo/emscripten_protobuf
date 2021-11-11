
Module.init = function (func) {
    __ATPOSTRUN__.push(func);
}

module.exports = Module;

// export default Module;
// export const xClass = Module.xClass;

