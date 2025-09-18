#include <iostream>
#include <cstdint>
struct int_literal {
    int value;
};

struct variable {
    int slot;
};
struct negation {
    struct expression* target;
};
struct addition {
    struct expression* left_term;
    struct expression* right_term;
};
enum expression_tag {
    EXPRESSION_INT_LITERAL,
    EXPRESSION_VARIABLE,
    EXPRESSION_NEGATION,
    EXPRESSION_ADDITION,
};
struct expression {
    enum expression_tag tag;
    struct {
        struct int_literal as_int_literal;
        struct variable as_variable;
        struct negation as_negation;
        struct addition as_addition;
    };
};
expression* int_literal(int value) {
    auto* result = new expression;
    result->tag = EXPRESSION_INT_LITERAL;
    result->as_int_literal.value = value;
    return result;
}
expression* variable(int slot) {
    auto* result = new expression;
    result->tag = EXPRESSION_VARIABLE;
    result->as_variable.slot = slot;
    return result;
}
expression* negation(expression* target) {
    auto* result = new expression;
    result->tag = EXPRESSION_NEGATION;
    result->as_negation.target = target;
    return result;
}
expression* addition(expression* left_term, expression* right_term) {
    auto* result = new expression;
    result->tag = EXPRESSION_ADDITION;
    result->as_addition.left_term = left_term;
    result->as_addition.right_term = right_term;
    return result;
}

void compile_expression(struct expression* e);
void compile_int_literal(struct int_literal* e) {
    printf("mov $%d, %%rax\n", e->value);
}
void compile_variable(struct variable* e) {
    int slot = e->slot;
    printf("mov %d(%%rsp), %%rax\n", -8 * (slot + 1));
}
void compile_negation(struct negation* e) {
    compile_expression(e->target);
    printf("neg %%rax\n");
}
int temp_counter = 10;
void compile_addition(struct addition* e) {
    compile_expression(e->left_term);
    int slot = temp_counter++; // allocate a new slot
    printf("mov %%rax, %d(%%rsp)\n", -8 * (slot + 1));
    compile_expression(e->right_term);
    printf("add %d(%%rsp), %%rax\n", -8 * (slot + 1));
    temp_counter--; // restore the counter
}
void compile_expression(struct expression* e) {
    switch (e->tag) {
        case EXPRESSION_INT_LITERAL:
            compile_int_literal(&e->as_int_literal);
            break;
        case EXPRESSION_VARIABLE:
            compile_variable(&e->as_variable);
            break;
        case EXPRESSION_NEGATION:
            compile_negation(&e->as_negation);
            break;
        case EXPRESSION_ADDITION:
            compile_addition(&e->as_addition);
            break;
    }
}

extern "C" int64_t foo(int64_t a, int64_t b);

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    //auto lang = "C++";
    //std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    // struct expression* e =
    //     addition(
    //         variable(0),
    //         negation(variable(42)));
    // compile_expression(e);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("expected: %d, got: %ld\n", i-j+42, foo(i, j));
        }
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}