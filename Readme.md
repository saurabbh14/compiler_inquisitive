# A few words ...
Designing a programming language is a fascinating process.
In the world of high-level APIs the need to interact with low-level
intricacies has reduced. However, understanding low-level details 
remains important for performance optimization, debugging, 
and systems programming. To go even further down, "how these 
programming languages are themselves programmed", that is a complete
mystery to me. Basically I lacked the understanding
of compiler/interpreter design. So, I started to dig into the
topic and what I found that although building a production-level
compiler is very complicated (not an easy task at all! Much respect!),
writing a simple and crude compiler for a limited syntax is
quite easy* (*once you understand the workings of Abstract Syntax Tree AST.
And I do not claim full understanding).

This repo is an attempt to gather together some tutorial works
and their attempted expansions in my pursuit to learn compiler
design. I don't claim this to be an original work rather more
of a follow along exercise and some curious excursions.

`compiler_crude` is my first attempt at writing a basic language parser
and generating an ASSEMBLY code. It is based on the blog post by [Sebastian
Mestre](https://sebmestre.blogspot.com/2023/11/en-writing-compiler-is-surprisingly.html).

`compiler_llvm` is much more involved project which uses a proper
workflow of lexer, parser and assembly(llvm). This is based on [an old
tutorial/post by Loren Segal](https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/)