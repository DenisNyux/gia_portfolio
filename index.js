const nav_links = document.querySelectorAll('.nav-link')
// const content = document.querySelectorAll('.content-page')

console.log(nav_links.length)



// nav_links.forEach((link)=>{
//     link.addEventListener('click', ()=>{
//         document.querySelectorAll('.nav-link').forEach(lnk => lnk.classList.remove('active'))
//         link.classList.add('active')
//         // document.querySelectorAll('.content-page').forEach(lnk => lnk.dis)
//     })
// })

function setAllUnactive() {
    const activated = document.querySelectorAll('content-page');
    activated.forEach(x => {
        console.log(x)
        x.classList.remove('content-page')
        x.classList.add('content-page-inactive')
    })
}


for (let i=0; i<nav_links.length; i++) {
    nav_links[i].addEventListener('click', ()=>{
        document.querySelectorAll('.nav-link').forEach(lnk => lnk.classList.remove('active'))
        nav_links[i].classList.add('active')
        const activated = document.querySelectorAll('.content-page');
        activated.forEach(x=> {
            x.classList.remove('content-page')
            x.classList.add('content-page-inactive')
        })
        const deactivated = document.querySelectorAll('.content-page-inactive');
        deactivated[i].classList.remove('content-page-inactive')
        deactivated[i].classList.add('content-page')
        // console.log(deactivated.length)
    })
}


// console.log(nav_links)

// for (let i =0; i<nav_links.length; i++) {
//     nav_links[i].addEventListener('click', () => {
//         document.querySelectorAll('.nav-link').forEach(lnk => lnk.classList.remove('active'));

//     })
// }

// function turn_off_all

