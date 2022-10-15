//////////////////////////////////////
// 外设中断
//////////////////////////////////////

void KeyboardInterrupt::KeyboardInterruptEntrance()
{
    SaveContext(); /* 保存中断现场 */

    SwitchToKernel(); /* 进入核心态 */

    CallHandler(Keyboard, KeyboardHandler); /* 调用键盘中断设备处理子程序 */

    /* 对主8259A中断控制芯片发送EOI命令。 */
    IOPort::OutByte(Chip8259A::MASTER_IO_PORT_1, Chip8259A::EOI);

    struct pt_context *context;
    __asm__ __volatile__("	movl %%ebp, %0; addl $0x4, %0 "
                         : "+m"(context));

    if (context->xcs & USER_MODE) /*先前为用户态*/
    {
        while (true)
        {
            X86Assembly::CLI(); /* 处理机优先级升为7级 */

            if (Kernel::Instance().GetProcessManager().RunRun > 0)
            {
                X86Assembly::STI(); /* 处理机优先级降为0级 */
                Kernel::Instance().GetProcessManager().Swtch();
            }
            else
            {
                break; /* 如果runrun == 0，则退栈回到用户态继续用户程序的执行 */
            }
        }
    }

    RestoreContext(); /* 恢复现场 */

    Leave(); /* 手工销毁栈帧 */

    InterruptReturn(); /* 退出中断 */
}

//////////////////////////////////////
// 时钟中断
//////////////////////////////////////

void Time::TimeInterruptEntrance()
{
    SaveContext(); /* 保存中断现场 */

    SwitchToKernel(); /* 进入核心态 */

    CallHandler(Time, Clock); /* 调用时钟中断处理子程序 */

    struct pt_context *context;
    __asm__ __volatile__("	movl %%ebp, %0; addl $0x4, %0 "
                         : "+m"(context));

    if (context->xcs & USER_MODE) /*先前为用户态*/
    {
        while (true)
        {
            X86Assembly::CLI(); /* 处理机优先级升为7级 */

            if (Kernel::Instance().GetProcessManager().RunRun > 0)
            {
                X86Assembly::STI(); /* 处理机优先级降为0级 */
                Kernel::Instance().GetProcessManager().Swtch();
            }
            else
            {
                break; /* 如果runrun == 0，则退栈回到用户态继续用户程序的执行 */
            }
        }
    }

    RestoreContext(); /* 恢复现场 */

    Leave(); /* 手工销毁栈帧 */

    InterruptReturn(); /* 退出中断 */
}

//////////////////////////////////////
// 异常
//////////////////////////////////////
/* 
 * 声明INT 0 - INT 31号异常在IDT中的入口函数(Entrance)
 * -->无出错码<-- 的异常
 */
#define IMPLEMENT_EXCEPTION_ENTRANCE(Exception_Entrance, Exception_Handler) \
    void Exception::Exception_Entrance()                                    \
    {                                                                       \
        SaveContext();                                                      \
                                                                            \
        SwitchToKernel();                                                   \
                                                                            \
        CallHandler(Exception, Exception_Handler);                          \
                                                                            \
        RestoreContext();                                                   \
                                                                            \
        Leave();                                                            \
                                                                            \
        InterruptReturn();                                                  \
    }

/* 
 * 声明INT 0 - INT 31号异常在IDT中的入口函数(Entrance)
 * -->有出错码(ErrCode)<-- 的异常
 * 由于出错码必须在iret中断返回指令之前手动从栈上弹出，
 * 所以有出错码的情况下，在leave指令销毁栈帧后，再跳过
 * 栈上的4个字节出错码。
 */
#define IMPLEMENT_EXCEPTION_ENTRANCE_ERRCODE(Exception_Entrance, Exception_Handler) \
    void Exception::Exception_Entrance()                                            \
    {                                                                               \
        SaveContext();                                                              \
                                                                                    \
        SwitchToKernel();                                                           \
                                                                                    \
        CallHandler(Exception, Exception_Handler);                                  \
                                                                                    \
        RestoreContext();                                                           \
                                                                                    \
        Leave();                                                                    \
                                                                                    \
        __asm__ __volatile__("addl $4, %%esp" ::);                                  \
                                                                                    \
        InterruptReturn();                                                          \
    }

//////////////////////////////////////
// 系统调用
//////////////////////////////////////

void SystemCall::SystemCallEntrance()
{
    SaveContext();

    SwitchToKernel();

    CallHandler(SystemCall, Trap);

    // 获取中断之前的状态
    struct pt_context *context;
    __asm__ __volatile__("	movl %%ebp, %0; addl $0x4, %0 "
                         : "+m"(context));

    // 开始判断是否需要调度
    if (context->xcs & USER_MODE) /*先前为用户态*/
    {
        while (true)
        {
            X86Assembly::CLI(); /* 处理机优先级升为7级 */

            if (Kernel::Instance().GetProcessManager().RunRun > 0)
            {
                X86Assembly::STI(); /* 处理机优先级降为0级 */
                Kernel::Instance().GetProcessManager().Swtch();
            }
            else
            {
                break; /* 如果runrun == 0，则退栈回到用户态继续用户程序的执行 */
            }
        }
    }
    RestoreContext(); /* 此后EAX中存放系统调用返回值，防止一切可能的修改 */

    Leave(); /* 手工销毁栈帧 */

    InterruptReturn(); /* 退出中断 */
}
