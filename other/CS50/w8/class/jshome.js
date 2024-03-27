//document.addEventListener('DOMContentLoaded', function() {
//    document.querySelector('form').addEventListener('submit', function(event) {
//        let name = document.querySelector('#name').value;
//        alert('Se cuide ' + name + '.');
//        event.preventDefault();
//    });
//});

document.addEventListener('DOMContentLoaded', function() {
    let map = document.querySelector('iframe');
    map.style.visibility = 'hidden';
    let soldado = document.querySelector('video');
    soldado.style.visibility = 'visible';
    let input = document.querySelector('input');
    input.addEventListener('keyup', function(event) {
        let name = document.querySelector('p');
        if (input.value) {
            name.innerHTML = `Se cuide ${input.value}.`;
            map.style.visibility = 'visible';
        }
        else {
            name.innerHTML = 'escreva seu nome cabeça oca';
            map.style.visibility = 'hidden';
        }
    });
});