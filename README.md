# JeremyVM
A virtual machine written in c++
# Logic
Two stacks, one is called "Stack", another one is called "Memory"
# Opcodes
0: HALT<br />
1: POP (Memory)<br />
2: PUSH (Memory)<br />
3: IADD (Memory) [Push (top + second)]<br />
4: ISUB (Memory) [Push (top - second)]<br />
5: IADD (Memory) [Push (top * second)]<br />
6: ISUB (Memory) [Push (top / second)]<br />
7: PRINT [Int value, not char value]<br />
8: STORE (Stack)<br />
9: LOAD (Stack->Memory) [Also Pop Stack]<br />
10: CALL [JMP]<br />
11: RET [Return]<br />
12: CMP (Memory) [Only store boolean, might be able to store size comparison later on]<br />
13: JNE [Jump if Not Equal]<br />
14: JE [Jump if Equal]<br />
15: MSTORE (Memory->Stack) [Also Pop Memory, basically reverse of LOAD]<br />
