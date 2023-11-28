#### Default values for some header fields
Since SQLite is a real-world project, it has to take into account for a lot of different things which are out of the scope of this project so a lot of values in the header table would not make sense to you but you cannot simple ignore them if you want to use tools to browse `*.sqlite` files. So, I am giving some default values for you to use.

-  **Page Size**: `4096`
-  **File format version numbers**: `1` and `1` for both write (at 18) and read (at 19)
-  **Schema cookie**: `0`
-  **Schema format number**: `4`
-  **Suggested cache size**: `204800`
-  **Incremental vacuum settings**: `0` and `0`
-  **Text encoding**: `2` which means utf16-le (little endian)
-  **User version number**: `1`
-  **Application ID**: `1`
-  **Write library version number and version-valid-for number**: `3044000` and `0`