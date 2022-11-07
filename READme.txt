- Để biên dịch code, mở terminal, cd đến thư mục chứa code, chạy dòng lệnh sau 
	g++ -g .\main.cpp .\Application.cpp .\CreateInput.cpp .\SortAlgorithm.cpp  -o main
    g++ -g ./main.cpp ./Application.cpp ./CreateInput.cpp ./SortAlgorithm.cpp  -o main
=> sẽ có file thực thi main.exe

- Cách chạy chương trình: ./main.exe [Cách tạo đầu vào] [loại đầu vào] [size] [thuật toán]
	+) Cách tạo đầu vào: "file", "create" - chỉ có "create" mới có loại đầu vào.
	+) Loại đầu vào: "random", "duplicated", "nsorted", "sorted", "rsorted".
	+) Thuật toán: "shell", "merge", "heap", "quick", "quick3", "bubble", "selection", "insertion" - "all" để chạy tất cả thuật toán

	Ví dụ: ./main.exe file shell merge quick3
		   ./main.exe create nsorted all

- Code gồm các thành phần:
	+) main.cpp: file chứa hàm main, k cần sửa j file này
	+) Application.cpp, Application.h: file này chứa chương trình, đọc cmt để biết nội dung các hàm 
	+) CreateInput.cpp,  CreateInput.h: file này để tạo mẫu, 1 mẫu có 2 tính chất là : loại mẫu và số lượng phần tử.
	+) SortAlgorithm.cpp, SortAlgorithm.h: file chứa thuật toán => MUỐN CHỈNH THUẬT TOÁN THÌ CHỈNH Ở 2 FILE NÀY.
	+) input.txt: chứa đầu vào cho thuật toán, muốn lấy đầu vào từ biên ngoài thì copy vào file này, nếu chọn create thì input do mình tạo cx auto được ghi vào file này
	+) folder Result: gồm mảng đã sắp xếp và các kết quả đo đạc.

- Lưu ý: đầu vào các thuật toán trong code sẽ có dạng struct input
	struct input {
		int value;
		int idx;
	}
=> đổi đầu vào mảng int arr[] => struct input arr[]
=> đổi arr[i] => arr[i].value
=> nếu thuật toán cần tạo giá trị trung gian như : int temp => đổi thành: struct input temp;


