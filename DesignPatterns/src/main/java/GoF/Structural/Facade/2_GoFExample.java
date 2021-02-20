package GoF.Structural.Facade;

/**
 * This example tries to show how we can put a facade on a compiler subsystem.
 * istream represents an stream of byteCodes. The Scanner class takes a stream
 * of characters and produces a stream of tokens, one token at a time
 * 
 * The class Parser uses a ProgramNodeBuilder to create a parse tree from a
 * Scanner's tokens.
 * 
 * Parser calls back on ProgramNodeBuilder to build the parse tree
 * incrementally. These classes interact according to the Builder (110) pattern.
 * 
 * ProgramNode is a composite. ProgramNode defines an interface for manipulating
 * the program node and its children, if any.
 * 
 * Classes StatementNode and ExpressionNode are statements in a computer
 * program. The CodeGenerator class is a visitor pattern, and it generates a
 * code from these statements, and gives it back as a BytecodeStream.
 * CodeGenerator has subclasses, for example, StackMachineCodeGenerator and
 * RISCCodeGenerator, that generate machine code for different hardware
 * architectures.
 * 
 * Each subclass of ProgramNode implements Traverse to call Traverse on its
 * child ProgramNode objects. In turn, each child does the same for its
 * children, and so on recursively.
 * 
 * The classes we've discussed so far make up the compiler subsystem. Now we'll
 * introduce a Compiler class, a facade that puts all these pieces together.
 * Compiler provides a simple interface for compiling source and generating code
 * for a particular machine.
 * 
 * All and all, Compiler is the facade of this entire schema, that puts everything together.
 * The compiler in this case was designed in particular for a RIISC system.
 */

class istream {

}

class Token {

}

class BytecodeStream {

}

class StatementNode {

}

class ExpressionNode {
}

class CodeGenerator {
    protected BytecodeStream _output;

    void Visit(StatementNode s) {

    }

    void Visit(ExpressionNode e) {

    }

    protected CodeGenerator(BytecodeStream b) {
    }

}

class ProgramNode {
    // program node manipulation
    void GetSourcePosition(int line, int index) {
    };

    // ...
    // child manipulation
    void Add(ProgramNode p) {

    }

    void Remove(ProgramNode p) {
    };

    void Traverse(CodeGenerator c) {

    };

}

class ProgramNodeBuilder {
    ProgramNode _node;

    ProgramNodeBuilder() {
    };

    ProgramNode NewVariable(char[] variableName) {
        return null;
    };

    ProgramNode NewAssignment(ProgramNode variable, ProgramNode expression) {
        return null;
    }

    ProgramNode NewReturnStatement(ProgramNode value) {
        return null;
    };

    ProgramNode NewCondition(ProgramNode condition, ProgramNode truePart, ProgramNode falsePart) {
        return null;
    }

    ProgramNode GetRootNode() {
        return null;
    };

}

class Scanner {
    istream _inputStream;

    Scanner(istream i) {

    };

    Token Scan() {
        return null;
    };
};

class Parser {
    void Parse(Scanner s, ProgramNodeBuilder p) {

    };
};

class Compiler {
    Compiler() {
    };

    void Compile(istream input, BytecodeStream output) {
    }
}