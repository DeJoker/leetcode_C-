#include "../common/debugger.h"

struct Data
{
	int32_t value;
};
 
int PromiseDemo()
{
	std::promise<Data> data_promise;      //创建一个承诺
	std::future<Data> data_future = data_promise.get_future();     //得到这个承诺封装好的期望
 
	std::thread prepareData_thread([](std::promise<Data> &data_promise){
		std::this_thread::sleep_for(std::chrono::milliseconds(200));    //模拟生产过程

		cout << GetUString() << " set value" << endl;
		// LOG_INFO << "set value";
		data_promise.set_value({ 1 });       //通过set_value()反馈结果
	}, std::ref(data_promise));
 
	std::thread processData_thread([](std::future<Data> &data_future){
		cout << data_future.get().value << "  xxx " <<   GetUString() << endl;
		// LOG_INFO << data_future.get().value;
		// std::cout << data_future.get().value << std::endl;    //通过get()获取结果
	}, std::ref(data_future));
 
	prepareData_thread.join();
	processData_thread.join();
 
	return 0;
}


void MultiPromiseDemo(int n)
{
	vector<std::promise<Data>> data_promises(n);
	vector<std::thread> threads(n);

	for(int i=0; i<n; ++i) {
		std::thread th([=](std::promise<Data> &data_promise){
			int value = rand()%1000;
			std::this_thread::sleep_for(std::chrono::milliseconds(value));    //模拟生产过程

			LOG_DEBUG << i << " produce " << value;
			data_promise.set_value({ value });       //通过set_value()反馈结果
		}, std::ref(data_promises[i]));
		threads[i] = std::move(th);
	}

	for(auto& prom : data_promises) { // 不能用const
		std::future<Data> data_future = prom.get_future();     //得到这个承诺封装好的期望
		LOG_DEBUG << data_future.get().value;
	}


	// std::this_thread::sleep_for(std::chrono::seconds(4));
	for (std::thread & th : threads)
	{
		// If thread Object is Joinable then Join that thread.
		if (th.joinable())
			th.join();
	}

	return;

}




int main() {
	srand(time(0));
	PromiseDemo();
	// MultiPromiseDemo(5);
	LOG_DEBUG << "end";
    // PromiseDemo();
}


