function checkPasswords() {
  let pass1 = document.getElementById("pass1").value;
  let pass2 = document.getElementById("pass2").value;
  if (pass1 == pass2) {
    document.getElementById("passed").innerHTML = "Passwords match";
    document.getElementById("passed").style.color = "green";
  }
  else {
    document.getElementById("passed").innerHTML = "Passwords do not match";
    document.getElementById("passed").style.color = "red";
  }
}