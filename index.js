var trigram = document.querySelector("nav.lacasa ul li.trigram");
Show = true;
function change() {
    var li = document.querySelectorAll("nav.lacasa ul li.menu");
    if (Show) {
        li.forEach(li => {

            li.style.display = "block";
        })
        trigram.innerHTML = "&#9776;";
        Show = !Show;
    }
    else {
        li.forEach(li => {
            li.style.display = "none";
        })

        trigram.innerHTML = "&times";
        Show = !Show;
    }
}
trigram.addEventListener("click", change);
