#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

class Hello :  public llvm::FunctionPass {
    public:
        static char ID;
        Hello() : FunctionPass(ID) {}

        bool runOnFunction(llvm::Function &F) override {
          llvm::errs() << "Hello, function ";
          llvm::errs().write_escaped(F.getName()) << '\n';
          return false;
        }
};

char Hello::ID = 0;
static llvm::RegisterPass<Hello> X("hello", "Hello World Pass");
