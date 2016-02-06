extern crate libc;

#[link(name = "mylib")]
extern {
    fn square(value: i32) -> i32;
}

#[no_mangle]
pub unsafe extern fn rs_mytest(input: i32) -> i32{
    square(input)
}

//cargo rustc --release -- -C link_args="-Wl,--subsystem,windows -L C:\local_projects\rust\andr\rust-in-node-examples\lib\build\Release -l mylib"
