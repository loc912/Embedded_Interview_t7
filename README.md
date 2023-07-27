# C PROGRAMMING LANGUAGE

<details> <summary> Chapter 1: C BASIC </summary> 
  
### 1. Variable
    
    - Trong Embedded system chúng ta sẽ sử dụng các kiểu dữ liệu uint8_t, uint16_t, uint32_t, uint64_t để khai báo kích thước cho biến.
    - VD: kích thước của biến a trong unit8_t a;  0 -> 2^8-1 (0-255)
          kích thước của biến b trong int8_t b;   ((-2^8)/2)-1 -> ((2^8)/2)-1 (-127->127)
    --> Chúng ta có thể sử dụng các kiểu khai báo trên để chọn kích thước phù hợp cho biến để tối ưu bộ nhớ. 
    
### 2. Typedef
      
    - Typedef được sử dụng để định nghĩa một tên mới cho một kiểu dữ liệu có sẵn.
    - VD: typedef int typeInt 
    --> typeInt: được định nghĩa lại nhưng bản chất vẫn là kiểu dữ liệu int.

### 3. Enum </summary>

      + kiểu Enum: 
            // Định nghĩa kiểu enum với tên là "Weekday"
            enum Weekday {
                Monday,
                Tuesday,
                Wednesday,
                Thursday,
                Friday,
                Saturday,
                Sunday
            };
          
      + Gía trị của các phần tử đầu tiên sẽ bằng 0 nếu không gán giá trị ban đầu và giá trị của phần tử sau sẽ tăng lên 1 đơn vị so với phần tử đứng trước.
</details>    
<details><summary> Chapter 2: POINTER </summary> 

### 1. Cách khai báo con trỏ. 

-   Cách khai báo con trỏ `int *p`  
+   Ex:
```C
    void main(){
        int a;
        int *p; 
        p=&a;
        printf("Gia trị tại địa chỉ a: %p",p); //lấy địa chỉ a.

        printf("Gia trị a: %p",*p); //lấy giá trị của a  
    }
```
### 2. Void pointer và cách ép kiểu dữ liệu 

- Cách khai báo void pointer: `void *ptr` là một con trỏ đặt biệt trong đó nó có thể trỏ được tới địa chỉ mọi đối tượng có kiểu khai báo khác nhau 
- Muốn dùng `void pointer` chúng ta phải ép kiểu dữ liệu cho nó về kiểu dữ liệu tương ứng với kiểu dữ liệu đối tượng muốn trỏ tới.  
- Ex:
```C
void main(){
    int i = 10; 
    double a = 10.1;
    void *ptr; 

    ptr=&i;
    printf("test i:%p",*(int*)ptr);

    ptr=&a;
    printf("test i:%p",*(double*)ptr);

}
```
### 3. NULL pointer 
-   `NULL pointer` là con trỏ có giá trị = 0 và địa chỉ = 0 . Khi khai báo một con trỏ mà không gáng giá trị cho nó thì nó sẽ trỏ tới địa chỉ rác hoặc có thể là một biến nào đó trong chương trình làm cho chương trình gặp lỗi. 
--> Khi khai báo một con trỏ thì phải gáng cho nó 1 giá trị nào đó . Nếu chưa dùng tới thì có thể gáng cho nó 1 giá trị `NULL`

### 4. Function pointer 
-   `Ex Function poiter :`
```c
void tong(int a, int b){
  printf("tong %d va %d = %d\n", a, b, a+b);
}
int main(void){
void (*ptr)(int,int);
ptr = &tong;
printf("Tong %d\n",ptr(4,5));
}
```
### 5. Pointer to pointer 

</details>

<details> <summary> Chapter 3: MEMORY ALLOCATION </summary>

![Alt text](https://github.com/loc912/Embedded_Interview_t7/assets/138952987/eb10e28b-ef36-400f-9685-94bec10225aa)

### 1. Text </summary>

  - Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction
  - Chứa khai báo hằng số trong chương trình (.rodata)
  EX: 
  ```C
    const int a =10;
  ```
  --> `Phần vùng này chỉ đọc đọc chứ không thay đổi được.`

### 2. Data (Initialized Data)

  - Quyền truy cập là `read-write`
  - Chứa biến toàn cục hoặc biến static với giá trị khởi tạo `khác 0`
  - Được giải phóng khi kết thúc chương trình

### 3. BSS (Uninitialized Data)

  - Quyền truy cập là `read-write`
  - Chứa biến toàn cục hoặc biến static với giá trị khởi tạo `bằng 0 `hoặc `không khỏi tạo`
  - Được giải phóng khi kết thúc chương trình
  --> `Tính từ lần đầu tiên khai báo. Tức là ban đầu khởi tạo ở BSS thì sẽ ở BSS, còn ban đầu khởi tạo ở Data thì sẽ ở Data.`

### 4. Stack

  - Quyền truy cập là `read-write`
  - Được sử dụng cấp phát cho biến local, input parameter của hàm,…
  - Sẽ được giải phóng khi ra khỏi block code/hàm (thu hồi)

### 5. Heap

  - Quyền truy cập là `read-write`
  - Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
  - Sẽ được giải phóng khi gọi hàm free,…

### 6. Cấp phát động

  - Malloc/Calloc: trả về con trỏ void (void*) nên cần ép kiểu dữ liệu trả về
  - Realloc: thay đổi kích thước ô nhớ

    Ex:
    ```c
      unit8_t *ptr = (unit8_t *)malloc(5);// Malloc tạo 5 ô nhớ mỗi ô nhớ 1 byte.
      unit6_t *ptr = (unit16_t *)malloc(10);// Malloc tạo 5 ô nhớ mỗi ô nhớ 2 byte.
    ```
  - Tổng quát:
  ```c
   unit8_t * ptr = (unit8_t *)malloc(sizeof(unit8_t)*5);
   unit16_t * ptr = (unit16_t *)malloc(sizeof(unit16_t)*5); 
   ptr = (unit16_t *)realloc(ptr,sizeof(unit16_t)*7);
   free(ptr); //Giải phóng 
  ```

### 7. So sánh Heap và Stack

  - Bộ nhớ `Heap` và bộ nhớ `Stack` bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong `RAM` khi chương trình được thực thi
  - Bộ nhớ `Stack` được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch
  - Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)

### 8. Kích thước vùng nhớ  
  - `Stack`: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn)
  - `Heap`: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình
  
### 9. Đặc điểm vùng nhớ
-  `Stack`: Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình
- `Heap`: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ

### 10. Vấn đề lỗi xảy ra đối với vùng nhớ*
-  `Stack`: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...

    Ví dụ về tràn bộ nhớ Stack với hàm đệ quy vô hạn:
    ```c
        int foo(int x){

          printf("De quy khong gioi han\n");
    
          return foo(x);
    
        }
    ```    
- `Heap`: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow), nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại
    
    EX: Trường hợp khởi tạo vùng nhớ Heap quá lớn:
    ```C
        int *A = (int *)malloc(18446744073709551615);
    ```
</details>
<details> <summary> Chapter 4: VARIABLE </summary>
 
### 1. Static
-   Biến `static` cục bộ (local static variable): Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.

-   Biến `static` toàn cục (global static variable): Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 

### 2.Extern 
-   ` Biến Extern ` dùng để khai báo một biến hoặc hàm nằm bên ngoài (externally) của phạm vi hiện tại, giúp truy cập vào chúng từ các tệp (files) hoặc phạm vi khác trong chương trình.
-   Ex: 
```C
    // file1.c
    int a = 10; // Biến toàn cục

    // Không cần sử dụng 'extern' ở đây, vì đã khai báo ở trên rồi.
```    
---
```c
    // file2.c
    #include <stdio.h>

    extern int a; // Khai báo biến toàn cục nằm trong file1.c

    int main() {
        printf("Global variable: %d\n", a); // In ra Global variable: 10
        return 0;
    }
```
### 3. Volatile 
- `volatile` được sử dụng để báo hiệu cho trình biên dịch biết rằng một biến có thể thay đổi bất kỳ lúc nào bên ngoài luồng chương trình hiện tại. Điều này thông báo trình biên dịch không nên tối ưu hóa truy cập đến biến đó bằng cách giả định rằng nó sẽ không thay đổi trong quá trình thực thi.
### 4. Register
</details>
<details> <summary> Chapter 5: STRUCTURE </summary>

### 1. Struct

- Bộ nhớ của một cấu trúc `struct` được tính bằng tổng kích thước của tất cả các `members `của cấu trúc đó, cộng thêm các `padding `nếu có.
  
### 2. Union

- Bộ nhớ của một `union` được tính bằng kích thước bằng kích thước kiến trúc vi xử lý. 
- EX: `Môi trường Windows 32 bit: 4 bytes` còn `Môi trường Windows 64 bit: 8 bytes`

### 3. So sánh Struct và Union

- Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:
**struct**: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)
**Union** : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.


</details>
<details> <summary> Chapter 6: COMPILER </summary>

### 1. Qui trình của một Compiler
- Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

  `Giai đoàn tiền xử lý (Pre-processor)`

  `Giai đoạn dịch NNBC sang Asembly (Compiler)`

  `Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)`

  `Giai đoạn liên kết (Linker)`

![alt text](https://github.com/loc912/Embedded_Interview_t7/assets/138952987/5d9058c7-795b-4678-a004-45e6b2030c18)
### 2. Giai đoạn tiền xử lý – Preprocessor
- Giai đoạn này sẽ thực hiện:
  **+ Nhận mã nguồn**
  **+ Xóa bỏ tất cả chú thích, comments của chương trình**
  **+ Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý**
- Ví dụ: chỉ thị `#include `cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng `#define `sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
### 3. Cộng đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly
- Phân tích cú pháp (syntax) của mã nguồn NNBC
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
### 4. Công đoạn dịch Assembly
- Dich chương trình => Sang mã máy 0 và 1
- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
### 5. Giai đoạn Linker
Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
- Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
- Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.

</details>

<details> <summary> Chapter 7: MACRO </summary>
### 1. Định nghĩa macro 
  - Chúng ta dịnh nghĩa macro bằng cách dùng lệnh `#define`
  - Trong quá trình tiền xử lí (pre-processor), Macro định nghĩa cái gì thì sẽ thay thế bằng chính cái đó trong quá trình tiền xử lý
  - VD:
```c
    #define PI 3.145654 // trong quá trình Preprocessor khi gặp bất kỳ biến `PI` nào thì sẽ được thay bằng `3.145654`
```
### 2.Khái niệm Ifndef,endif
   

    ```c
     #define STM32 // macrio STM32

     #ifndef STM32 // nếu đã define STM32 thì câu lệnh bên trong không được thực hiện 
     int a=10;
     #endif       // dùng để kết thúc định nghĩa
    ```
</details>

<details> <summary> Chapter 8: FUNCTION </summary>

</details>
