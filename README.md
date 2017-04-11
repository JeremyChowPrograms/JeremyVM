# JeremyVM
A virtual machine written in c++
# Logic
Two stacks, one is called "Stack", another one is called "Memory"
# Opcodes
0: HALT
1: POP (Memory)
2: PUSH (Memory)
3: IADD (Memory) [Push (top + second)]
4: ISUB (Memory) [Push (top - second)]
5: IADD (Memory) [Push (top * second)]
6: ISUB (Memory) [Push (top / second)]
7: PRINT [Int value, not char value]
8: STORE (Stack)
9: LOAD (Stack->Memory) [Also Pop Stack]
10: CALL [JMP]
11: RET [Return]
12: CMP (Memory) [Only store boolean, might be able to store size comparison later on]
13: JNE [Jump if Not Equal]
14: JE [Jump if Equal]
15: MSTORE (Memory->Stack) [Also Pop Memory, basically reverse of LOAD]
