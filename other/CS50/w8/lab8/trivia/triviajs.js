document.addEventListener('DOMContentLoaded', function() {
    let answered = false;
    let won = false;
    let correct = document.querySelector('.correct');
    correct.addEventListener('click', function() {
        if (answered === false) {
            correct.style.backgroundColor = 'green';
            document.querySelector('answer').innerHTML = "Correct!";
            answered = true;
            won = true;
        }
        else if (won === true) {
            document.querySelector('answered').innerHTML = "You've already won. stop clicking things silly!";
        }
        else {
            document.querySelector('answered').innerHTML = "You've already made your guess, but the answer was indeed Brasilia";
        }
    });

    let incorrect = document.querySelectorAll('.incorrect');
    for (let i = 0; i < incorrect.length; i += 1) {
        incorrect[i].addEventListener('click', function() {
            if (answered === false) {
                incorrect[i].style.backgroundColor = 'red';
                document.querySelector('answer').innerHTML = "Incorrect";
                answered = true;
            }
            else if (won === true) {
                document.querySelector('answered').innerHTML = "You've already won. stop clicking things silly!";
            }
            else {
                document.querySelector('answered').innerHTML = "You've already tried it once, but the answer was: Brasilia";
            }
        });
    }
    let check = document.querySelector('.checkanswer');
    var football = 'football';
    var soccer = 'soccer';
    let q2input = document.querySelector('input');
    check.addEventListener('click', function() {
        var q2answer = document.getElementById('q2answer').value.toLowerCase();
        if (q2answer === football) {
            q2input.style.backgroundColor = 'green';
            document.querySelector('q2check').innerHTML = "Correct!";
        }
        else if (q2answer === soccer) {
            document.querySelector('q2check').innerHTML = "Correct!?? IT'S FOOTBALL!!!";
            q2input.style.backgroundColor = 'green';
        }
        else {
            document.querySelector('q2check').innerHTML = "Incorrect"
            q2input.style.backgroundColor = 'red';
        }
    });
})