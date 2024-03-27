document.addEventListener('DOMContentLoaded', function() {
    history.scrollRestoration = "manual";

    // go to the top of the screen after reloading
    $(window).on('beforeunload', function(){
        $(window).scrollTop(0);
    });
})