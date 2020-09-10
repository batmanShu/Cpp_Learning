# 目录
<!-- GFM-TOC -->
- [目录](#目录)
- [多态](#多态)
  - [静态多态](#静态多态)
    - [函数重载](#函数重载)
      - [为什么C语言不能实现函数重载](#为什么c语言不能实现函数重载)
    - [模板](#模板)
    - [宏定义](#宏定义)
  - [动态多态](#动态多态)
    - [虚函数](#虚函数)
- [关键字](#关键字)
  - [static](#static)
  - [const](#const)
  - [virtual](#virtual)
  - [extern](#extern)
  - [inline](#inline)
  - [volatile](#volatile)
  - [friend](#friend)
  - [mutable](#mutable)
  - [constexpr](#constexpr)
- [c++11](#c11)
  - [智能指针](#智能指针)
  - [右值](#右值)
    - [std::move](#stdmove)
    - [std::forward](#stdforward)
- [stl](#stl)
- [其他(未归类)](#其他未归类)
<!-- GFM-TOC -->

# 多态

## 静态多态
编译时的多态

### 函数重载

基于不同的参数列表，同一个函数名字可以指向不同的函数定义，实现原理在于编译器根据不同的参数列表对同名函数进行名字重整，而后这些同名函数就变成了彼此不同的函数

#### 为什么C语言不能实现函数重载
编译器在编译.c文件时，只会给函数进行简单的重命名；具体的方法是给函数名之前加上”_”;所以加入两个函数名相同的函数在编译之后的函数名也照样相同；调用者会因为不知道到底调用那个而出错

### 模板

### 宏定义

## 动态多态
运行时的多态

### 虚函数

# 关键字
## static
## const
## virtual
## extern
## inline
## volatile
## friend
## mutable
## constexpr

# c++11
## 智能指针
## 右值
### std::move
### std::forward


# stl

# 其他(未归类)
