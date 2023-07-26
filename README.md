# C PROGRAMMING LANGUAGE

<details> <summary> B1: C BASIC </summary> 
  
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
