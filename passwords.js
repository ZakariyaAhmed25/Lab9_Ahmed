function validate() {
    var Password1 = document.getElementById("Password1").value;
    var Password2 = document.getElementById("Password2").value;

    if (Password1.length < 8) {
        alert("Password 1 must be atleast 8 letters long")
    } else if (Password2.length < 8) {
        alert("Password 2 must be at least 8 letters long")
    } else if (Password1 != password2) {
        alert("Passwords don't match")
    } else {
        alert("Passwords match")
    }
}