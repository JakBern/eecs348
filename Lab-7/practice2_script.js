function updateColors() {
  let r_bg = document.getElementById("redbg").value;
  let g_bg = document.getElementById("greenbg").value;
  let b_bg = document.getElementById("bluebg").value;
  let r_bord = document.getElementById("redborder").value;
  let g_bord = document.getElementById("greenborder").value;
  let b_bord = document.getElementById("blueborder").value;
  let bord_width = document.getElementById("borderwidth").value;
  document.getElementById("example").style.backgroundColor = rgb(r_bg, g_bg, b_bg);
  document.getElementById("example").style.borderColor = rgb(r_bord, g_bord, b_bord);
  document.getElementById("example").style.borderWidth = bord_width + "px";
}

// stolen from stackoverflow
function rgb(r, g, b) {
  return ["rgb(",r,",",g,",",b,")"].join("");
}