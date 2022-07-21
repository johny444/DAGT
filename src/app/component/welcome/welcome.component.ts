import { Component, OnInit } from '@angular/core';
import { UserService } from 'src/app/share/UserServices/user.service';

@Component({
  selector: 'app-welcome',
  templateUrl: './welcome.component.html',
  styleUrls: ['./welcome.component.css']
})
export class WelcomeComponent implements OnInit {
  private islogin!:boolean
  constructor(private checkLog:UserService) { }

  ngOnInit(): void {
    this.checkLog.currentLoggedIn.subscribe(res=>{
      this.islogin=res
    })
  }

}
