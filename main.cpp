#include <glog/logging.h>
#include <iostream>
#include <unistd.h>

void DivideNumbers(int a, int b) {
    if (b == 0) {
        LOG(ERROR) << "Divide by zero error!";
        return;
    }

    double result = static_cast<double>(a) / b;
    LOG(INFO) << "Result of division: " << result;
}

int main() {
    // 初始化glog
    google::InitGoogleLogging("zhanghui_log");  // 设置日志文件名前缀
    FLAGS_log_dir = "/home/zhanghui/Desktop/Glog_pro/build/";  // 设置日志输出目录

    // 设置日志级别（可选）
    google::SetStderrLogging(google::INFO);  // 将INFO级别以上的日志同时输出到标准错误输出

    FLAGS_colorlogtostderr = true;  //使能log颜色
    FLAGS_max_log_size = 256;   //设置log 的最大文件大小 最大日志大小（MB）
    FLAGS_stop_logging_if_full_disk = true; //当磁盘满的时候，不写
    FLAGS_logbufsecs = 0;//设置log的输出速率 缓冲区超时，自动刷入log文件，设置为0是实时打印
    // FLAGS_logtostderr =true;

    auto tmp = "zhanghui";
    // 记录不同级别的日志
    for (int i =0 ; i < 100 ;i++) {
        sleep(2);
        LOG(INFO) << "This is an informational message:" << i;  //变量直接加载后面即可，自动判定
        LOG(WARNING) << "This is a warning message:" << tmp << i;
        LOG(ERROR) << "This is an error message." << i;
    }
 

    // 调用一个可能会产生错误的函数
    DivideNumbers(10, 0);

    // 清理glog资源
    google::ShutdownGoogleLogging();

    return 0;
}
