let offset = 0;
const sliderLine = document.querySelector('.slider-line');

document.querySelector('.slider-next').addEventListener('click', function(){
    offset = offset + 670;
    if (offset > 2600) {
        offset = 0;
    }
    sliderLine.style.left = -offset + 'px';
});

document.querySelector('.slider-prev').addEventListener('click', function () {
    offset = offset - 650;
    if (offset < 0) {
        offset = 2600;
    }
    sliderLine.style.left = -offset + 'px';
});