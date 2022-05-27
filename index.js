const nav_links = document.querySelectorAll('.nav-link')
// console.log(nav_links)

// for (let i =0; i<nav_links.length; i++) {
//     nav_links[i].addEventListener('click', () => {
//         document.querySelectorAll('.nav-link').forEach(lnk => lnk.classList.remove('active'));

//     })
// }



nav_links.forEach((link)=>{
    link.addEventListener('click', ()=>{
        document.querySelectorAll('.nav-link').forEach(lnk => lnk.classList.remove('active'))
        link.classList.add('active')
        // document.querySelectorAll('.content-page').forEach(lnk => lnk.dis)
    })
})




// function turn_off_all

