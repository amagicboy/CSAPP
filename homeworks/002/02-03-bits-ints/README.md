## 总结

### 1、逻辑右移、算术右移转换
+ 逻辑右移补0，把补0的位 置1 变为算术右移
+ 算术右移补1，把补1的位 置0 变为逻辑右移

### 2、统计1的个数
前一半和后一般异或，同为1则抵消，剩下的是对位只有1个1或者全为0的情况，最后结果是最低位

### 3、表示最高位的1
先把x转换为形如 [ 000111 ... 1 ] 的格式，x减去（x-1）得到最高位1的二进制表示

### 4、[ 1000 ... 000 ] [ 1111 ... 000 ] [ 000 ... 111 ]
+ [ 1000 ... 000 ]: 有符号数 -0 转换为 无符号数
+ [ 1111 ... 000 ]: 有符号数 -0 右移 再转换为无符号数
+ [ 0000 ... 111 ]: 有符号数 -0 右移 然后转换为无符号数再按位取反（如果是1左移再减1，考虑到左移32位会溢出）


### 5、n 位二进制长度表示的最大、最小有符号数
提取出符号位，在考虑把数值位截断出来，最后再加上符号位

### 6、判断有符号数是否溢出
同为正，若和符号位为负，则正溢；同为负，若和符号位为正，则负溢

### 7、异或判断是否相等
先异或再取反